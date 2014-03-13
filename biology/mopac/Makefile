# Created by: Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
# $FreeBSD$

PORTNAME=	mopac
PORTVERSION=	7.${MOPAC_SUBVERSION}
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	SF/${PORTNAME}7/${PORTNAME}7/${PORTNAME}7-1.00
DISTNAME=	${PORTNAME}7-${MOPAC_SUBVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Semi-empirical (MNDO, etc.) molecular orbital calculation

LIB_DEPENDS=	libf2c.so:${PORTSDIR}/lang/f2c

USES=		gmake
USE_AUTOTOOLS=	aclocal automake autoconf libtool
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing --copy
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MOPAC_SUBVERSION=	1.11

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/s|$$(libdir)|$$(prefix)/libdata|g' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e '/usage/s|run_||g' \
		-e 's|./src/mopac7|${PREFIX}/libexec/mopac7|g' \
		${WRKSRC}/run_${PORTNAME}7

.include <bsd.port.options.mk>

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run_${PORTNAME}7 ${PREFIX}/bin/${PORTNAME}7
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/${PORTNAME}7 ${PREFIX}/libexec/${PORTNAME}7
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}/test
	${INSTALL_DATA} ${WRKSRC}/tests/*.dat ${EXAMPLESDIR}/test
.endif

.include <bsd.port.mk>
