# ex:ts=8
# Ports collection makefile for:  mixal
# Date created:			  21-Dec-1996
# Whom:                 	  David O'Brien <obrien@cs.ucdavis.edu>
#
# $FreeBSD$
#

PORTNAME=	mixal
PORTVERSION=	1.06
CATEGORIES=	lang
MASTER_SITES=	http://www.ccil.org/retro/  \
		ftp://locke.ccil.org/pub/retro/
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	obrien@FreeBSD.org

EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| ${SED} -e '1,/^This ought/d' |sh
NO_WRKSUBDIR=	yes
ALL_TARGET=

DOCDIR=		${PREFIX}/share/doc/mix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mix ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/READ.ME ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/MIX.DOC ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/notes ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/opcodes ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*.mix ${DOCDIR}
.endif

.include <bsd.port.mk>
