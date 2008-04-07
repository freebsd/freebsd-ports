# New ports collection makefile for:	evolution-data-server
# Date created:				09 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/evolution-data-server/Makefile,v 1.142 2008/03/10 20:33:29 mezz Exp $
#

PORTNAME=	evolution-data-server
PORTVERSION=	2.22.1
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The data backends for the Evolution integrated mail/PIM suite

LIB_DEPENDS=	soup-2.4.1:${PORTSDIR}/devel/libsoup \
		nss3.1:${PORTSDIR}/security/nss \
		tasn1.3:${PORTSDIR}/security/libtasn1

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	build
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
		--with-libdb=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR} ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

PLIST_SUB=	VERSION="2.22" EVO_VERSION="1.2"

OPTIONS=	IMAP4	"Enable experimental IMAP4 backend" off

.include <bsd.port.pre.mk>

.if ( ( ${OSVERSION} < 504101 ) || ( ${OSVERSION} >= 600000 && ${OSVERSION} < 600012 ) )
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-libedataserver_e-msgport.c
.endif

.if defined(HEIMDAL_HOME) || defined(WITH_HEIMDAL)
HEIMDAL_HOME?=	${LOCALBASE}
LIB_DEPENDS+=		krb5:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME} --with-krb5-includes=${HEIMDAL_HOME}/include
.elif !defined(NO_KERBEROS)
CONFIGURE_ARGS+=        --with-krb5=/usr
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
