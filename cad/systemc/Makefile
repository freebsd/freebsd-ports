# New ports collection makefile for:   systemc
# Date created:        15 December 2005
# Whom:                Daniel Thiele
#
# $FreeBSD$
#

PORTNAME=	systemc
PORTVERSION=	2.1.v1
CATEGORIES=	cad devel
EXTRACT_SUFX=	.tgz

MAINTAINER=	dthiele@gmx.net
COMMENT=	A modeling platform for system-level C++ models

RESTRICTED=	"You have to register at http://www.systemc.org/account/register.php first"

USE_AUTOTOOLS=	aclocal:19 automake:19 autoheader:259 autoconf:259
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_SCRIPT=	../configure

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		is restricted. You have to register at http://www.systemc.org/account/register.php and download ${DISTFILES} from there first. Then put ${DISTFILES} into ${DISTDIR} and run make again
.endif

do-configure:
	@${MKDIR} ${WRKSRC}/objdir
	@(cd ${WRKSRC}/objdir && \
	${CONFIGURE_ENV} && \
	${CONFIGURE_SCRIPT} --prefix=${PREFIX}/${PORTNAME})

do-build:
	@(cd ${WRKSRC}/objdir && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
	${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC}/objdir && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
	${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
