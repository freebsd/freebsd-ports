# New ports collection makefile for:	preps-gui
# Date created:		Fri Mar 19 14:27:30 EET 2004
# Whom:			shadow@psoft.net
#
# $FreeBSD$
#

PORTNAME=	preps
PORTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://webpages.charter.net/stuffle/preps/download/files/
PKGNAMESUFFIX=	-gui
DISTNAME=	preps-${PORTVERSION}
DIST_SUBDIR=	prep

MAINTAINER=	jmelo@freebsdbrasil.com.br
COMMENT=	Problem reporting system

RUN_DEPENDS=	prepsdb_tool:${PORTSDIR}/devel/prepstools

BROKEN=		Removes /usr/X11R6/share/pixmaps directory

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 gconf2 libgnomeui
USE_PGSQL=	yes
INSTALLS_OMF=	yes
GCONF_SCHEMAS=	preps.schema

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-pgsqldir=${LOCALBASE} \
			--with-plpgsqldir=${LOCALBASE} \
			--with-libprepsdir=${LOCALBASE} \
			--localstatedir=/var

post-patch:
	@${REINPLACE_CMD} -e 's#^\(omf_dest_dir\).*#\1=${PREFIX}/share/gnome/omf/@PACKAGE@#' \
		${WRKSRC}/omf.make ${WRKSRC}/help/C/Makefile.in

.include <bsd.port.mk>
