# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	mercurialserver
PORTVERSION=	1.2.0
CATEGORIES=	devel python
MASTER_SITES=	http://dev.lshift.net/paul/mercurial-server/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${SNAME}_${SVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software for hosting mercurial repositories

LICENSE=	GPLv2

RUN_DEPENDS=	hg:devel/mercurial

WRKSRC=		${WRKDIR}/${SNAME}_${SVERSION}.orig
SNAME=		mercurial-server
SVERSION=	1.2

HGUSER=		hg
HGGROUP=	hg
USERS=		${HGUSER}
GROUPS=		${HGGROUP}

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} \
		HGUSER=${HGUSER}
PKGMESSAGE=	${WRKDIR}/pkg-message

USES=		python
USE_PYTHON=	distutils autoplist

HGSVCONF_FILES=	access.conf \
		remote-hgrc.d/access.rc \
		remote-hgrc.d/logging.rc

pre-patch:
	${SED} -I .orig -e "s#/etc/mercurial-server/#${PREFIX}/etc/${PORTNAME}/#" ${WRKSRC}/src/init/dot-mercurial-server

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/remote-hgrc.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/keys/users
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/keys/root
.for i in ${HGSVCONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/src/init/conf/${i} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/${i}
.endfor

.include <bsd.port.mk>
