# New ports collection makefile for:	evolution-data-server
# Date created:				09 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/evolution-data-server/Makefile,v 1.83 2006/04/13 07:52:30 bland Exp $
#

PORTNAME=	evolution-data-server
PORTVERSION=	1.6.1
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The data backends for the Evolution integrated mail/PIM suite

LIB_DEPENDS=	soup-2.2.8:${PORTSDIR}/devel/libsoup \
		nss3.1:${PORTSDIR}/security/nss \
		tasn1.2:${PORTSDIR}/security/libtasn1

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnometarget libgnomeui \
		ltverhack
USE_OPENLDAP=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static \
		--enable-nss=yes \
		--with-openldap=yes \
		--with-nss-includes=${LOCALBASE}/include/nss/nss \
		--with-nss-libs=${LOCALBASE}/lib \
		--with-nspr-includes=${LOCALBASE}/include/nspr \
		--with-nspr-libs=${LOCALBASE}/lib \
		--with-krb5=/usr
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

PLIST_SUB=	VERSION="1.6" EVO_VERSION="1.2"

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

.include <bsd.port.post.mk>
