# New ports collection makefile for:	filezilla
# Date created:				2006-10-24
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	filezilla
PORTVERSION=	3.5.3
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	SF/${PORTNAME}/FileZilla_Client/${PORTVERSION}
DISTNAME=	FileZilla_${PORTVERSION}_src

MAINTAINER=	jsa@FreeBSD.org
COMMENT=	Fast and reliable cross-platform FTP, FTPS, and SFTP client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils
BUILD_DEPENDS:=	${RUN_DEPENDS}
LIB_DEPENDS=	gcrypt.18:${PORTSDIR}/security/libgcrypt \
		gnutls.47:${PORTSDIR}/security/gnutls \
		idn.17:${PORTSDIR}/dns/libidn \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		tinyxml.3:${PORTSDIR}/textproc/tinyxml

MAKE_JOBS_SAFE=	yes

INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_WX=		2.8
WX_CONF_ARGS=	relative
WX_UNICODE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		filezilla.1 fzputtygen.1 fzsftp.1
MAN5=		fzdefaults.xml.5

OPTIONS=	DBUS	"Enable D-BUS intergration"	On \
		NLS	"Native Language Support"	On

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--with-dbus
.else
CONFIGURE_ARGS+=	--without-dbus
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-locales
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--disable-manualupdatecheck
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's|(dummy) wxrc|\1 ${WXRC_CMD:T}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
