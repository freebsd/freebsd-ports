# New ports collection makefile for:	viewcvs
# Date created:				Sun 02 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	viewvc
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://viewvc.tigris.org/files/documents/3330/41694/

MAINTAINER=	pgollucci@p6m7g8.com
COMMENT=	Web-based Version Control Repository Browsing

RUN_DEPENDS=	${PYTHON_LIBDIR}/site-packages/svn/__init__.py:${PORTSDIR}/devel/py-subversion \
		${PYTHON_LIBDIR}/site-packages/_mysql.so:${PORTSDIR}/databases/py-MySQLdb

USE_PYTHON=	yes
.if defined (WITH_APACHE)
USE_APACHE=	2.0+
.endif
.if defined(WITH_MODPYTHON3)
RUN_DEPENDS+=	${APACHEMODDIR}/mod_python.so:${PORTSDIR}/www/mod_python3
.endif
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	INSTDIR="${PREFIX}/${INSTDIR}"

INSTDIR?=	${PORTNAME}
PLIST_SUB=	INSTDIR=${INSTDIR}

do-install:
	@(cd ${WRKSRC} && ${PYTHON_CMD} viewvc-install --prefix=${PREFIX}/${INSTDIR} --destdir="" --clean-mode=false)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
