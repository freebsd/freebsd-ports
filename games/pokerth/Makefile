# New ports collection makefile for:	pokerth
# Date created:		24 Jun 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pokerth
PORTVERSION=	0.7.1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	PokerTH-${PORTVERSION}-src

MAINTAINER=	mad@madpilot.net
COMMENT=	A poker game written in C++/QT4

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		mikmod.2:${PORTSDIR}/audio/libmikmod \
		gnutls.26:${PORTSDIR}/security/gnutls \
		curl.5:${PORTSDIR}/ftp/curl

USE_ICONV=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui corelib qmake_build moc_build rcc_build uic_build
USE_SDL=	mixer
HAS_CONFIGURE=	yes
QMAKE_ARGS+=	-unix PREFIX=${PREFIX}

PORTDOCS=	server_setup_howto.txt
MAN1=		pokerth.1

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|/usr([a-z|/]*)|${LOCALBASE}/\1|g' \
		-e 's|(-lcurl)|\1 -liconv|g' \
		-e 's:boost_([a-z]+)-[-|a-z|0-9|_]*:boost_\1:g' \
		-e 's|LIB_DIRS =.*|LIB_DIRS = ${LOCALBASE}/lib|g' \
		${WRKSRC}/*.pro

do-configure:
	@cd ${CONFIGURE_WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS} pokerth.pro

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/pokerth ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/pokerth_server ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/docs/${MAN1} ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/server_setup_howto.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
