# New ports collection makefile for:   sqsh
# Date created:		14 Jan 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	sqsh
PORTVERSION=	2.1
PORTREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	http://www.sqsh.org/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	kiesel@schlund.de
COMMENT=	Interactive tool for querying Sybase database servers

LIB_DEPENDS=	ct.2:${PORTSDIR}/databases/freetds

USE_GETTEXT=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SYBASE="${LOCALBASE}"
CONFIGURE_ARGS=	--with-readline
ALL_TARGET=	build

MAN1=	sqsh.1

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
.else
USE_MOTIF=	yes
CONFIGURE_ARGS+=	--with-motif
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/doc/global.sqshrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sqsh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/sqsh.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/global.sqshrc ${PREFIX}/etc/sqshrc.default

.include <bsd.port.mk>
