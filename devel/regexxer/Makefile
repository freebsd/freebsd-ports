# New ports collection makefile for:	regexxer
# Date created:				15 February 2003
# Whom:					Rui Lopes <rui@ruilopes.com>
#
# $FreeBSD$
#

PORTNAME=		regexxer
PORTVERSION=		0.4
PORTREVISION=		2
CATEGORIES=		devel textproc gnome
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE} \
			${MASTER_SITE_SOURCEFORGE:S/$/:pcre/} \
			ftp://ftp.csx.cam.ac.uk/pub/software/programming/%SUBDIR%/:pcre
MASTER_SITE_SUBDIR=	${PORTNAME} \
			${PCRE_NAME}/:pcre
DISTFILES=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
			$(PCRE_NAME)-${PCRE_VERSION}${EXTRACT_SUFX}:pcre

MAINTAINER=		rui@ruilopes.com
COMMENT=		An interactive tool for performing search and replace operations

LIB_DEPENDS=		gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_GNOME=		gnomehack gnomeprefix gnometarget
CONFIGURE_ARGS=		PCRE_CONFIG="${PCRE_WRKDIR}/.install/bin/pcre-config"

PCRE_NAME=		pcre
PCRE_VERSION=		4.4
PCRE_WRKDIR=		${WRKDIR}/${PCRE_NAME}-${PCRE_VERSION}

pre-configure:
	@(cd ${PCRE_WRKDIR} && \
		$(ECHO_CMD) "Configuring PCRE... " && \
		${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INSTALL="/usr/bin/install" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		./configure --enable-utf8 --disable-shared --prefix="${PCRE_WRKDIR}/.install" && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} $(INSTALL_TARGET))

.include <bsd.port.mk>
