# New ports collection makefile for:	A-A-P Recipe Executive: aap
# Date created:				28 October 2002
# Whom:					Bram Moolenaar <bram@a-a-p.org>
#
# $FreeBSD$
#

PORTNAME=	aap
PORTVERSION=	1.090
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	a-a-p

MAINTAINER=	ports@FreeBSD.org
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

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} >= 2.5
EXTRA_PATCHES=	${FILESDIR}/extra-Sign.py
.endif

do-install:
	@cd ${WRKSRC} && \
		${PYTHON_CMD} ./aap PREFIX="${PREFIX}" FULLDOCS=${FULLDOCS} \
			HTMLDIR=/html install

test: install
	cd ${WRKSRC}; ${PREFIX}/bin/aap

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX}|${SED} -E 's,.*share/nls/.+$$,,g;s,${PORTVERSION},%%PORTVERSION%%,g;s,^(lib/aap/Exec-%%PORTVERSION%%/doc/),%%PORTDOCS%%\1,g;s,^share/doc/aap/.*,,g'|${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.post.mk>
