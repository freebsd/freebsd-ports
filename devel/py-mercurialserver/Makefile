# New ports collection Makefile for:	mercurialserver
# Date Created:				12 Sep 2010
# Whom:					Aldis Berjoza <aldis@bsdroot.lv>
#
# $FreeBSD$
#

PORTNAME=	mercurialserver
PORTVERSION=	1.0.1
CATEGORIES=	devel python
MASTER_SITES=	http://dev.lshift.net/paul/mercurial-server/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${SNAME}_${PORTVERSION}

MAINTAINER=	aldis@bsdroot.lv
COMMENT=	Software for hosting mercurial repositories

RUN_DEPENDS=	hg:${PORTSDIR}/devel/mercurial

WRKSRC=		${WRKDIR}/${SNAME}_${PORTVERSION}.orig
LICENSE=	GPLv2
SNAME=		mercurial-server

HGUSER=		hg
HGGROUP=	hg

USE_PYTHON=	2.6+
USE_PYDISTUTILS=YES
PYDISTUTILS_PKGNAME=${SNAME}

CONF_FILES=	access.conf \
		remote-hgrc.d/access.rc \
		remote-hgrc.d/logging.rc

.include <bsd.port.pre.mk>
pre-patch:
	${SED} -I .orig -e "s#/etc/mercurial-server/#${PREFIX}/etc/${PORTNAME}/#" ${WRKSRC}/src/init/dot-mercurial-server

pre-su-install:
	@${SETENV} PKG_PREFIX=${PREFIX} GITUSER=${HGUSER} \
		GITGROUP=${HGGROUP} GITHOME=${HGHOME} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}/remote-hgrc.d
	${MKDIR} ${PREFIX}/etc/${PORTNAME}/keys/users
	${MKDIR} ${PREFIX}/etc/${PORTNAME}/keys/root
.for i in ${CONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/src/init/conf/${i} ${PREFIX}/etc/${PORTNAME}/${i}
.endfor
	${MV} ${PREFIX}/hg/dot-mercurial-server ${PREFIX}/hg/.mercurial-server
	${MV} ${PREFIX}/hg/hgadmin-hgrc ${PREFIX}/hg/.hgadmin-hgrc
	${RM} ${PREFIX}/hg/hginit
	${MKDIR} ${PREFIX}/hg/.ssh
	${MKDIR} ${PREFIX}/hg/repos
	${CHOWN} -R ${HGUSER}:${HGGROUP} ${PREFIX}/hg
	@${ECHO_MSG}
	@${ECHO_MSG} "NOTE: ${PORTNAME} has been patched to use ${PREFIX}/etc/${PORTNAME}"
	@${ECHO_MSG} "      instead of /etc/mercurial-server"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
