#!/usr/bin/env python

from copy import copy
from os import chdir, makedirs, rename
from os.path import basename, dirname, isdir, isfile, join
from sys import argv
from zipfile import ZIP_DEFLATED, ZipFile, ZipInfo

def parse(destdir, entry):
    target, source = entry.decode('utf-8').strip().split('|')
    target = target.split('::')
    return join(destdir, target[0]), None if len(target) == 1 else target[1], source


def main(archivefile, destdir):
    archives = {}
    seen = []
    with ZipFile(archivefile, 'r') as archive:
        for entry in archive.open("index.txt"):
            target, entry_name, source = parse(destdir, entry)
            data = archive.read(source)
            path = dirname(target)
            if not isdir(path):
                makedirs(path)
            if entry_name is None:
                with open(target, 'wb') as file:
                    file.write(data)
            else:
                if target not in archives:
                    archives[target] = ZipFile(target, 'w', ZIP_DEFLATED)
                zipinfo = copy(archive.getinfo(source))
                zipinfo.filename = entry_name
                archives[target].writestr(zipinfo, data)
    for archive in archives.values():
        archive.close()


if __name__ == "__main__":
    main(*argv[1:])
