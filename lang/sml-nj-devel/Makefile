# New ports collection makefile for: sml/nj
# Date created:        7 July 1998
# Whom:                jkoshy
#
# $FreeBSD$
#

PORTNAME=	smlnj
PORTVERSION=	110.33
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.research.bell-labs.com/dist/smlnj/working/110.33/ \
		ftp://ftp.diku.dk/pub/smlnj/working/110.33/ \
		ftp://sunsite.doc.ic.ac.uk/computing/programming/languages/ml/smlnj/working/110.33/ \
		ftp://compiler.kaist.ac.kr/pub/sml/working/110.33/
DISTFILES=	boot.x86-unix.tgz compiler.tgz cm.tgz ckit.tgz config.tgz  \
		ml-burg.tgz ml-lex.tgz \
		ml-nlffi-lib.tgz ml-nlffigen.tgz \
		ml-yacc.tgz runtime.tgz \
		smlnj-lib.tgz system.tgz
EXTRACT_ONLY=	config.tgz

MAINTAINER=	jkoshy@freebsd.org

# Other mirror sites that generally carry only released versions of SML
# 	ftp://rodin.stanford.edu/pub/smlnj/release/
# 	ftp://ftp.cl.cam.ac.uk/MIRRORED/smlnj/release/
# 	ftp://ftp.ntua.gr/pub/lang/smlnj/release/
# Mirror sites that keep files around in gzipped format
# 	ftp://flint.cs.yale.edu/pub/smlnj/working/110.9.1/

DIST_SUBDIR=	sml-nj/${PORTVERSION}
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
NO_BUILD=	yes

NO_LATEST_LINK=	yes

MLEXE=	ml-build ml-makedepend sml ml-yacc ml-lex ml-burg ml-nlffigen

# make symlinks to the dist files
post-extract:
	cd ${WRKDIR} && ${LN} -sf ${_DISTDIR}/*  .
	${CP} ${FILESDIR}/targets.customized ${WRKDIR}/config/targets.customized

# The install target attempts to build and install the system
do-install:
	${MKDIR} ${PREFIX}/smlnj
	cd ${WRKDIR} && unset PWD && \
	FILESDIR="$(FILESDIR)" PATCH="$(PATCH)" PATCH_ARGS="$(PATCH_ARGS)" \
	INSTALLDIR="$(PREFIX)/smlnj"	./config/install.sh

post-install:
.for f in $(MLEXE)
	${LN} -s $(PREFIX)/smlnj/bin/$f $(PREFIX)/bin/$f
.endfor

.include <bsd.port.mk>
