# New ports collection makefile for:    frontbase
# Date created:                         Mon Apr 16 07:07:22 EST 2007
# Whom:                                 Quinton Dolan <q@onthenet.com.au>
#
# $FreeBSD$
#

PORTNAME=	FrontBase
PORTVERSION=	4.2.9
CATEGORIES=	databases
MASTER_SITES=	http://www.frontbase.com/download/Download_${PORTVERSION}/FreeBSD5/:db
MASTER_SITES+=	http://www.frontbase.com/download/WO5Plugin/UnixLinux/:plugin
DISTFILES=	FrontBase-${PORTVERSION}-FreeBSD5.tar:db

MAINTAINER=	mjs@bur.st
COMMENT=	Frontbase SQL Database Server

LICENSE=	FrontBase
LICENSE_NAME=	FrontBase
LICENSE_FILE=	${FILESDIR}/LICENSE.txt
LICENSE_PERMS=	no-auto-accept # nothing else allowed either

NO_PACKAGE=	license requires confirmation

USE_RC_SUBR=	frontbase
USE_LDCONFIG=	yes
SUB_FILES+=	pkg-message

ONLY_FOR_ARCHS=	i386

# Binary is built for 5.X :
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x

USERS=		frontbase
GROUPS=		frontbase
NO_BUILD=	yes
FBPKGNAME=	Package.tar.gz
FBDATADIRS=	Collations Library Translations

post-extract:
	@(cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${WRKSRC}/${FBPKGNAME} ${EXTRACT_AFTER_ARGS})

do-install:
	@${MKDIR} ${PREFIX}/FrontBase
	@${ECHO_MSG} -n ">> Installing FrontBase..."
.for dir in ${FBDATADIRS}
	@(cd ${WRKSRC}/FrontBase/${dir} && ${COPYTREE_SHARE} \* \
		${PREFIX}/FrontBase/${dir}/)
.endfor
	@(cd ${WRKSRC}/FrontBase/bin && ${COPYTREE_BIN} \* \
		${PREFIX}/FrontBase/bin/)
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/FrontBase/Documentation && \
		${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
	@(cd ${WRKSRC}/FrontBase/include && ${CP} -R * \
		${PREFIX}/include)
	@(cd ${WRKSRC}/FrontBase/lib && ${CP} -R * \
		${PREFIX}/lib)
	@${LN} -f ${PREFIX}/FrontBase/bin/sql92 ${PREFIX}/bin/sql92
	@${ECHO_MSG} " [ DONE ]"

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
