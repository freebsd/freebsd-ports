# New ports collection makefile for:   sqsh
# Date created:		14 Jan 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	sqsh
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.sqsh.org/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tds.0:${PORTSDIR}/databases/freetds \
		intl.4:${PORTSDIR}/devel/gettext

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
