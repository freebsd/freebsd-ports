@r@
identifier f;
position p;
@@
f@p(...)

@script:python@
p << r.p;
@@
print("hit: %s:%s" % (p[0].file, p[0].line))
