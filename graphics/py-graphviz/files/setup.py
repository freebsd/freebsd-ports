# $FreeBSD$

from distutils.core import setup, Extension

VERSION = '"py-agraph 1.0"'
agraph_srcs = [
	'apply.c', 'attr.c', 'edge.c', 'agerror.c', 'flatten.c', 
	'grammar.c', 'graph.c', 'id.c', 'imap.c', 'io.c', 'mem.c', 
	'node.c', 'obj.c', 'pend.c', 'rec.c', 'refstr.c', 'scan.c',
	'subg.c', 'utils.c', 'write.c'
]
cdt_srcs = [
	'dtclose.c', 'dtdisc.c', 'dtflatten.c', 'dthash.c', 'dtmethod.c',
	'dtopen.c', 'dtsize.c', 'dtextract.c', 'dtrestore.c', 'dtlist.c',
	'dtstat.c', 'dttree.c', 'dtview.c', 'dtrenew.c', 'dtwalk.c', 'dtstrhash.c'
]
cdt_srcs = ['../cdt/'+f for f in cdt_srcs]

setup(name = 'graphviz',
	version = '0.1',
	description = 'Python Interface to GraphViz',
	author = 'Manos Renieris',
	packages = ['graphviz'],
	ext_modules = [Extension('graphviz.graphviz', ['gv_wrap.c'] + cdt_srcs + agraph_srcs,
			include_dirs=['../cdt', '.'],
			define_macros=[('ulong','u_long'), ('VERSION', VERSION)])]
)
