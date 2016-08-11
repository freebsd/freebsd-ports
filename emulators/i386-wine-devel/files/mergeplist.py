#!/usr/bin/env python2

import sys

# <recipe url="http://code.activestate.com/recipes/576694/" license="MIT">
# added peek() method
import collections

class OrderedSet(collections.MutableSet):

    def __init__(self, iterable=None):
        self.end = end = [] 
        end += [None, end, end]         # sentinel node for doubly linked list
        self.map = {}                   # key --> [key, prev, next]
        if iterable is not None:
            self |= iterable

    def __len__(self):
        return len(self.map)

    def __contains__(self, key):
        return key in self.map

    def add(self, key):
        if key not in self.map:
            end = self.end
            curr = end[1]
            curr[2] = end[1] = self.map[key] = [key, curr, end]

    def discard(self, key):
        if key in self.map:
            key, prev, next = self.map.pop(key)
            prev[2] = next
            next[1] = prev

    def peek(self, last=False):
        end = self.end
        curr = end[1] if last else end[2]
        if curr is not end:
            return curr[0]
        raise IndexError("OrderedSet is empty, cannot peek item")

    def __iter__(self):
        end = self.end
        curr = end[2]
        while curr is not end:
            yield curr[0]
            curr = curr[2]

    def __reversed__(self):
        end = self.end
        curr = end[1]
        while curr is not end:
            yield curr[0]
            curr = curr[1]

    def pop(self, last=False):
        if not self:
            raise KeyError('set is empty')
        key = self.end[1][0] if last else self.end[2][0]
        self.discard(key)
        return key

    def __repr__(self):
        if not self:
            return '%s()' % (self.__class__.__name__,)
        return '%s(%r)' % (self.__class__.__name__, list(self))

    def __eq__(self, other):
        if isinstance(other, OrderedSet):
            return len(self) == len(other) and list(self) == list(other)
        return set(self) == set(other)
#</recipe>

def main(plists):
    prev = prev_short = None
    for line in gen_list(plists):
        if line.startswith("%%"):
            line_short = line.split("%%", 3)[1:]
            line_short = "%%%%%s%%%%%s" % (line_short[0].split("-", 2)[0], line_short[1])
            if prev_short == line_short:
                print(line_short)
                line = line_short = None
            elif prev is not None:
                print(prev)
            prev, prev_short = line, line_short
        else:
            if prev is not None:
                print(prev)
                prev = prev_short = None
            print line
    if prev is not None:
        print(prev)

def gen_list(plists):
    plists_len = len(plists)
    plists.sort(key=lambda x: int(x.rsplit('.', 2)[-1].split('-', 2)[0]))
    names = ["OSREL" + plist.rsplit('.', 2)[-1] for plist in plists]
    for i in range(plists_len):
        with open(plists[i], 'r') as file:
            plists[i] = OrderedSet(line.strip() for line in file.readlines())
    empty = sum(len(plist) == 0 for plist in plists)
    while empty < plists_len:
        # Test if the top of the plists are all common
        if not empty:
            line = plists[0].peek()
        if not empty and all(line == plist.peek() for plist in plists):
            yield line
            for plist in plists:
                plist.pop()
        else:
            # Find which of the plists have non-common lines
            lines = {}
            for i in range(plists_len):
                while len(plists[i]) and not all(plists[i].peek() in plist for plist in plists):
                    lines.setdefault(plists[i].pop(), []).append(names[i])
            for line in sorted(lines.keys()):
                suffix = lines[line][0].split('-', 2)
                suffix = len(suffix) == 2 and suffix[-1]
                if suffix and all(name.split('-', 2)[-1] == suffix for name in lines[line]):
                    yield "%%" + suffix + "%%" + line
                else:
                    for name in lines[line]:
                        yield "%%" + name + "%%" + line
        empty = sum(len(plist) == 0 for plist in plists)

if __name__ == '__main__':
    main(sys.argv[1:])
