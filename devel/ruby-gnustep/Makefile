# New ports collection makefile for:	Ruby/GNUstep
# Date created:		14 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep
PORTVERSION=	0.2.2
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rigs-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A Ruby interface to the GNUstep development environment

USE_RUBY=	yes
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes

GNUSTEP_PREFIX?=	${LOCALBASE}/GNUstep
GNUSTEP_LOCAL_ROOT=	${GNUSTEP_PREFIX}/Local
GNUSTEP_SYSTEM_ROOT=	${GNUSTEP_PREFIX}/System
GNUSTEP_NETWORK_ROOT=	${GNUSTEP_PREFIX}/Network
GNUSTEP_USER_ROOT=	${GNUSTEP_PREFIX}/Local/Users
GNUSTEP_MAKEFILES=	${GNUSTEP_SYSTEM_ROOT}/Library/Makefiles

MAKE_ENV+=	GNUSTEP_FLATTENED=yes

.include <bsd.port.pre.mk>

MAKEFILE=	GNUmakefile
MAKE_ENV+=	GNUSTEP_LOCAL_ROOT=${GNUSTEP_LOCAL_ROOT} \
		GNUSTEP_SYSTEM_ROOT=${GNUSTEP_SYSTEM_ROOT} \
		GNUSTEP_NETWORK_ROOT=${GNUSTEP_NETWORK_ROOT} \
		GNUSTEP_USER_ROOT=${GNUSTEP_USER_ROOT} \
		GNUSTEP_MAKEFILES=${GNUSTEP_MAKEFILES} \
		PATH=${PATH}:${GNUSTEP_SYSTEM_ROOT}/Tools
NO_FILTER_SHLIBS=	yes

post-extract:
	${FIND} ${WRKSRC}/ -type f -name '.cvsignore' -delete
	${FIND} -d ${WRKSRC}/ -type d -name CVS -exec ${RM} -rf "{}" ";"

post-patch:
	${RUBY} -i~ -p \
		-e 'gsub(/-lpthread/, "-pthread");' \
		-e 'gsub(/-lgmodel/, "");' \
		${WRKSRC}/Source/${MAKEFILE}
	${FIND} ${WRKSRC}/ -type f | \
		${XARGS} ${RUBY} -i -pe 'gsub(/ ruby -/, " ${RUBY} -")'

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/Examples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.if !defined(GNUSTEP_WITH_BASE_GCC)
TARGLIB!=	(cd ${PORTSDIR}/${GNUSTEP_GCC_PORT} && make -V TARGLIB)
.endif

.include <bsd.port.post.mk>
