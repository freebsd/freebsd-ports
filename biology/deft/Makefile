# New ports collection makefile for:	DeFT
# Date created:				1999-01-11
# Whom:					Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	deft
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://theory.chem.uottawa.ca/pub/
DISTNAME=	DeFT_${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp

WRKSRC=		${WRKDIR}/${DISTNAME}/source

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400005
# Using g77 is troublesome, then it is better to use f2c/cc.
BUILD_DEPENDS=	ftn77:${PORTSDIR}/lang/f77
.endif

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g"\
		${WRKDIR}/${DISTNAME}/examples/DeFT

post-configure:
	${CP} ${FILESDIR}/Makefile.deft ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/DeFT.exec ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/examples/DeFT ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/share/doc/DeFT
	${MKDIR} ${PREFIX}/share/DeFT
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/bases ${PREFIX}/share/DeFT/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/DeFT
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README_Liability \
		${PREFIX}/share/doc/DeFT/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/input.* \
		${PREFIX}/share/doc/DeFT/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/install.* \
		${PREFIX}/share/doc/DeFT/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/README \
		${PREFIX}/share/examples/DeFT
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/*.dft \
		${PREFIX}/share/examples/DeFT
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/*.out \
		${PREFIX}/share/examples/DeFT
.endif

.include <bsd.port.post.mk>
