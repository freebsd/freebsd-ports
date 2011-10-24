# Ports collection makefile for:	cc65
# Date created:			8 May 2000
# Whom:				Tim Vanderhoek <hoek@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cc65
PORTVERSION=	2.13.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.musoftware.de/pub/uz/cc65/ \
		http://www.funet.fi/pub/cbm/programming/cc65/ \
		http://www.acc.umu.se/~arvid/cc65_mirror/ \
		http://bj.spline.de/cc65/
DISTNAME=	${PORTNAME}-sources-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-compiler for 6502-based systems, includes 65816 assembler

USE_SUBMAKE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/cc65-${PORTVERSION}
MAKEFILE=	${WRKSRC}/make/gcc.mak
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

post-patch:
#
# CFLAGS safety
#
	@(${FIND} ${WRKSRC}/ -name gcc.mak -type f|${XARGS} ${REINPLACE_CMD} -E \
		-e "s,=[[:space:]]*-g -O2 -Wall -W(.*),+=\1," \
		-e "s,=[[:space:]]*-g -O2 -Wall(.*),+=\1," \
		-e "s,=[[:space:]]*-O2 -g -Wall -W(.*),+=\1," \
		-e "s,-std=c89,-std=c99,g" \
		-e "s,CC[[:space:]]*=.*,#&,")
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e "s,(install:.*)install-docs(.*)$$,\1\2," \
		-e '/\(MKDIR\)[[:space:]]+\$$\(CC65DOC\)/d' \
		${WRKSRC}/make/gcc.mak
	@${REINPLACE_CMD} -E -e "s,^(docdir[[:space:]]*=).*,\1," \
		-e "s,^(CC65_DOC[[:space:]]*=).*,\1," ${WRKSRC}/make/gcc.mak
.endif

# XXX: gmake>=3.82 hack:  beats the hell out of me.  Quick fix.
pre-install:
	@${MKDIR} -p ${PREFIX}/lib/cc65/tgi

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
