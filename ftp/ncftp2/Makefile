# Created by: ache
# $FreeBSD$

PORTNAME=	ncftp
PORTVERSION=	2.4.3
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FTP replacement with advanced user interface

LICENSE=	GPLv2

OPTIONS_DEFINE=	READLINE
OPTIONS_DEFAULT=READLINE
READLINE_DESC=	Enable readline support

USES=		ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_func_getmaxyx=yes
MAKE_JOBS_SAFE=	yes

MAN1=		ncftp2.1
PLIST_FILES=	bin/${LATEST_LINK}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREADLINE}
USES+=		readline
.else
CONFIGURE_ARGS+=--disable-readline
.endif

.if defined(INSTALL_AS_NCFTP)
LATEST_LINK=	ncftp
.else
LATEST_LINK=	ncftp2
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Use INSTALL_AS_NCFTP=yes to install ncftp2 as ${PREFIX}/bin/ncftp"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e \
		's|^exdirs=.*|exdirs=""|' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ncftp ${PREFIX}/bin/${LATEST_LINK}
	${INSTALL_MAN} ${WRKSRC}/ncftp.1 ${MANPREFIX}/man/man1/ncftp2.1

.include <bsd.port.mk>
