# Created by: G. Adam Stanislav
# $FreeBSD$

PORTNAME=	intel2gas
PORTVERSION=	1.3.3
CATEGORIES=	lang
MASTER_SITES=	http://www.niksula.cs.hut.fi/~mtiihone/intel2gas/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts Intel assembly language (nasm) to AT&T syntax (gas)

GNU_CONFIGURE=	yes
MAKE_ARGS=	CXX="${CXX}"

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/intel2gas ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "i2g g2i m2g" ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} BUGS DATAFILES README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
