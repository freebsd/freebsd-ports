# New ports collection makefile for:	evolution-data-server
# Date created:				09 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/evolution-data-server/Makefile,v 1.112 2007/03/13 04:35:01 marcus Exp $
#

PORTNAME=	evolution-data-server
PORTVERSION=	1.10.3.1
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The data backends for the Evolution integrated mail/PIM suite

LIB_DEPENDS=	soup-2.2.8:${PORTSDIR}/devel/libsoup \
		nss3.1:${PORTSDIR}/security/nss \
		tasn1.3:${PORTSDIR}/security/libtasn1

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnometarget libgnomeui \
		ltverhack
USE_OPENLDAP=	yes
USE_AUTOTOOLS=	libtool:15
USE_BDB=	41
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static \
		--enable-nss=yes \
		--with-openldap=yes \
		--with-krb5=/usr \
		--with-libdb=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR} ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

PLIST_SUB=	VERSION="1.10" EVO_VERSION="1.2"

OPTIONS=	IMAP4	"Enable experimental IMAP4 backend" off

.include <bsd.port.pre.mk>

.if ( ( ${OSVERSION} < 504101 ) || ( ${OSVERSION} >= 600000 && ${OSVERSION} < 600012 ) )
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-libedataserver_e-msgport.c
.endif

.if ${OSVERSION} >= 500000 && !defined(NO_KERBEROS) && \
	exists(/usr/lib/libkrb5.so)
CONFIGURE_ARGS+=	--with-krb5=/usr
.else
LIB_DEPENDS+=		krb5:${PORTSDIR}/security/heimdal
.if defined(HEIMDAL_HOME)
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME} --with-krb5-includes=${HEIMDAL_HOME}/include
.else
CONFIGURE_ARGS+=	--with-krb5=${LOCALBASE}
.endif
.endif

.if defined(WITH_IMAP4) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-imap4=yes
PLIST_SUB+=		IMAP4=""
.else
PLIST_SUB+=		IMAP4="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
