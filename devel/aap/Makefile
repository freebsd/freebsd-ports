# New ports collection makefile for:	A-A-P Recipe Executive: aap
# Date created:				28 October 2002
# Whom:					Bram Moolenaar <bram@a-a-p.org>
#
# $FreeBSD$
#

PORTNAME=	aap
PORTVERSION=	1.040
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	a-a-p

MAINTAINER=	rui@ruilopes.com
COMMENT=	A build tool alternative to make with internet access and CVS support

MAN1=		aap.1

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USE_PYTHON=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if !defined(NOPORTDOCS)
FULLDOCS=yes
.else
FULLDOCS=no
.endif

do-install:
	@cd ${WRKSRC} && \
		${PYTHON_CMD} ./aap PREFIX="${PREFIX}" FULLDOCS=${FULLDOCS} \
			HTMLDIR=/html install

test: install
	cd ${WRKSRC}; ${PREFIX}/bin/aap

.include <bsd.port.mk>
