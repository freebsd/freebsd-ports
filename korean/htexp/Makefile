# New ports collection makefile for:    hTeXp
# Date created:                 Jun 29 2000
# Whom:                         CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hTeXp
PORTVERSION=	1996.02.12
CATEGORIES=	korean print
MASTER_SITES=	ftp://knot.kaist.ac.kr/pub/htex/htexp/freebsd/ \
		ftp://knot.kaist.ac.kr/pub/htex/htexp/linux/ \
		ftp://knot.kaist.ac.kr/pub/htex/hlatexp/
DISTFILES=	htexp-freebsd-3.2 tex.poo unpacked.tar.gz
DIST_SUBDIR=	htex
EXTRACT_ONLY=	unpacked.tar.gz

MAINTAINER=	cjh@FreeBSD.org

# it depends teTeX.
RUN_DEPENDS=	virtex:${PORTSDIR}/print/teTeX

TEXMF=		${PREFIX}/share/texmf

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 320000
BROKEN=	"Systems prior to 3.2-RELEASE is out of support"
.endif

# htexp binary is built on 3.2-RELEASE.
.if ${OSVERSION} > 400000 && !exists(/usr/lib/compat/libc.so.3)
LIB_DEPENDS+=	c.3:${PORTSDIR}/misc/compat3x
.endif

do-build:
	### build htexpini script
	${SED} -e "s@%%TEXMF%%@${TEXMF}@g" \
	          < ${FILESDIR}/htexpini.in > ${WRKDIR}/htexpini

do-install:
	${MKDIR} ${TEXMF}/htexpformats
	${CHMOD} a+rx ${TEXMF}/htexpformats
	# htexp and friends
	${INSTALL_PROGRAM} ${_DISTDIR}/htexp-freebsd-3.2 ${PREFIX}/bin/htexp
	${INSTALL_SCRIPT} ${WRKDIR}/htexpini ${PREFIX}/bin/
	${INSTALL_DATA} ${_DISTDIR}/tex.poo ${TEXMF}/htexpformats
	### build hlatex.fmt
	( cd ${WRKDIR}/unpacked && \
	  ${ECHO_CMD} "R\n" | ${PREFIX}/bin/htexpini hlatex.ltx || \
	  ${TRUE} )
	${INSTALL_DATA} ${WRKDIR}/unpacked/hlatex.fmt \
			${TEXMF}/htexpformats/
	### rehash
	${PREFIX}/bin/texhash

.include <bsd.port.post.mk>
