# New ports collection makefile for:	porttools
# Date created:		2003-06-18
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	porttools
PORTVERSION=	0.63
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Tools for testing and submitting port updates and new ports

RUN_DEPENDS=	portlint:${PORTSDIR}/devel/portlint \
		sudo:${PORTSDIR}/security/sudo

.if defined(WITH_NEWFILE) || exists(${LOCALBASE}/bin/newfile)
RUN_DEPENDS+=	${LOCALBASE}/bin/newfile:${PORTSDIR}/devel/newfile
.endif

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install-docs
.endif

MAKE_ENV=	PREFIX="${PREFIX}" DATADIR="${DATADIR}" DOCSDIR="${DOCSDIR}"
MAN1=		port.1
MAN5=		porttools.5

.include <bsd.port.mk>
