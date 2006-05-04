# New ports collection makefile for:	Firebird-devel
# Date created:		03 December 2001
# Whom:			Chris Knight <chris@e-easy.com.au>
#
# $FreeBSD$
#

PORTNAME=	firebird
PORTVERSION=	2.0.a3
CATEGORIES=	databases
MASTER_SITES=	http://www.ramenzoni.com.br/~garga/firebird/ \
		http://www.galle.com.br/~garga/firebird/ \
		http://www.brainsoft.com.br/~garga/firebird/
MASTER_SITE_SUBDIR=	firebird
PKGNAMESUFFIX=	-devel
DISTNAME=	firebird2-20050726

MAINTAINER=	skv@FreeBSD.org
COMMENT=	The open-source InterBase(tm) 6.0 spin-off (Classic version)

USE_BZIP2=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=	autoconf:259:env libtool:15:env
GNU_CONFIGURE=		yes
USE_GCC=		3.4

DOCSDIR=	${PREFIX}/firebird/doc

CONFLICTS=	firebird-client-1.*

WRKSRC=		${WRKDIR}/firebird2
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/firebird/lib
SUB_FILES=	pkg-message pkg-install

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Does not build on FreeBSD-4.x"
.endif

pre-everything::
	@${ECHO_MSG} "WARNING: The on-disk structure of the databases has"
	@${ECHO_MSG} "changed since version 1.5.x."
	@${ECHO_MSG} "Cancel this installation now and backup your databases"
	@${ECHO_MSG} "if you have not already done so."
.if !defined(BATCH)
	@sleep 10
.endif

post-patch:
	@${REINPLACE_CMD} 's,InstallPrefix/etc,${LOCALBASE}/etc,g' \
		${WRKSRC}/builds/install/arch-specific/freebsd/install.sh.in

do-configure:
	@(cd ${WRKSRC} && ${SETENV} CC=${CC} CXX=${CXX} MAKE=${GMAKE}	\
	${AUTOTOOLS_VARS} ./autogen.sh --prefix=${PREFIX}/firebird	\
	--with-lock-manager --with-editline)

do-build:
	@(								\
	cd ${WRKSRC};							\
	${SETENV} CC=${CC} CXX=${CXX} ${GMAKE} all;			\
	)

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/sql.extensions
	${INSTALL_DATA} ${WRKSRC}/doc/README.* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sql.extensions/* \
		${DOCSDIR}/sql.extensions
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
