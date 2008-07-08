#
# $FreeBSD$
#

PORTSDIR=	../incoming-PRs/ports/
INDEX=		INDEX-6
MODULES_HEAD=	modules.head
MODULES_SRC=	src/CVSROOT/modules
MODULES_PROJ=	projects/CVSROOT/modules
MODULES_DOC=	doc/CVSROOT/modules
MODULES_PORTS=	ports/CVSROOT/modules
CVSUSER=	edwin

NOW!=		date "+%A %d %B %Y at %H:%M"

all: modules

commit: modules
	cp modules ports/CVSROOT/
	cd ports/CVSROOT; \
	cvs commit -m "Ports modules update at ${NOW}" modules


modules: ${MODULES_HEAD} modules.index
	cat ${MODULES_HEAD} modules.index > modules

modules.index: modules-ports modules-src modules-projects modules-doc
	./buildmodules.pl \
		--portsdir=${PORTSDIR} \
		--index=${INDEX} \
		--outdir=modules.dir \
		--outmod=modules.mod \
		--header=${MODULES_HEAD} \
		--modules-src=${MODULES_SRC} \
		--modules-proj=${MODULES_PROJ} \
		--modules-doc=${MODULES_DOC} \

	(cat modules.dir; cat modules.mod) > modules.index

modules-ports: ports
	cd ports; \
	cvs -d :ext:${CVSUSER}@pcvs.freebsd.org/home/pcvs co CVSROOT/modules; \
	cd ..
	cp ports/CVSROOT/modules modules-ports
modules-doc: doc
	cd doc; \
	cvs -d :ext:${CVSUSER}@ncvs.freebsd.org/home/dcvs co CVSROOT/modules; \
	cd ..
	cp doc/CVSROOT/modules modules-doc
modules-projects: projects
	cd projects; \
	cvs -d :ext:${CVSUSER}@ncvs.freebsd.org/home/projcvs co CVSROOT/modules; \
	cd ..
	cp projects/CVSROOT/modules modules-projects
modules-src: src
	cd src; \
	cvs -d :ext:${CVSUSER}@ncvs.freebsd.org/home/ncvs co CVSROOT/modules; \
	cd ..
	cp src/CVSROOT/modules modules-src

ports:
	mkdir ports
projects:
	mkdir projects
doc:
	mkdir doc
src:
	mkdir src

clean:
	-rm modules.index
	-rm modules modules.mod modules.dir
	-rm modules-ports modules-src modules-doc modules-projects
	-rm -rf src/CVSROOT ports/CVSROOT doc/CVSROOT projects/CVSROOT
