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

RUN_DEPENDS=	hg:${PORTSDIR}/devel/mercurial

WRKSRC=		${WRKDIR}/${SNAME}_${SVERSION}.orig
SNAME=		mercurial-server
SVERSION=	1.2

HGUSER=		hg
HGGROUP=	hg
USERS=		${HGUSER}
GROUPS=		${HGGROUP}

USE_PYTHON=	2.6+
USE_PYDISTUTILS=YES
PYDISTUTILS_PKGNAME=${SNAME}
PYDISTUTILS_PKGVERSION=${SVERSION}

HGSVCONF_FILES=	access.conf \
		remote-hgrc.d/access.rc \
		remote-hgrc.d/logging.rc

.include <bsd.port.pre.mk>
pre-patch:
	${SED} -I .orig -e "s#/etc/mercurial-server/#${PREFIX}/etc/${PORTNAME}/#" ${WRKSRC}/src/init/dot-mercurial-server

post-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}/remote-hgrc.d
	${MKDIR} ${PREFIX}/etc/${PORTNAME}/keys/users
	${MKDIR} ${PREFIX}/etc/${PORTNAME}/keys/root
.for i in ${HGSVCONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/src/init/conf/${i} ${PREFIX}/etc/${PORTNAME}/${i}
.endfor
	@${ECHO_MSG}
	@${ECHO_MSG} "NOTE: ${PORTNAME} has been patched to use ${PREFIX}/etc/${PORTNAME}"
	@${ECHO_MSG} "      instead of /etc/mercurial-server"
	@${ECHO_MSG}
	@${ECHO_MSG} "Now you need to create ${HGUSER} home (if nessacery) and run"
	@${ECHO_MSG} "      ${PREFIX}/etc/hginit as ${HGUSER} user from home directory"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
