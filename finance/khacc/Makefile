# New ports collection makefile for:	khacc
# Date created:		22 Jan 2003
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	khacc
PORTVERSION=	3.3
PORTREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qhacc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple KDE-base financial manager

LIB_DEPENDS=	qhacc.7:${PORTSDIR}/finance/qhacc
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_KDELIBS_VER=	3
USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
WANT_AUTOMAKE_VER=	19
WANT_AUTOCONF_VER=	259
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-qhacc-config=${X11BASE}/bin
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -pi -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/khacc/khacc.in

pre-configure:
	@cd ${CONFIGURE_WRKSRC} \
		&& ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} -I ${ACLOCAL_DIR} \
		&& ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} ${AUTOMAKE_ARGS} \
		&& ${PERL} admin/am_edit \
		&& ${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF} ${AUTOCONF_ARGS} \
		&& ${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' configure

.include <bsd.port.post.mk>
