# New ports collection makefile for:	automake
# Date created:		15 March 1997
# Whom:			FUJIMOTO Kensaku <fujimoto@oscar.elec.waseda.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	automake
PORTVERSION=	1.4.5
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	automake
DISTNAME=	automake-1.4-p5

MAINTAINER=	ade@FreeBSD.org
COMMENT=	GNU Standards-compliant Makefile generator (legacy version 1.4)

BUILD_VERSION=	14
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
LATEST_LINK=	automake${BUILD_VERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PERL5}
CONFIGURE_ARGS=	--program-suffix=${BUILD_VERSION}
USE_PERL5=	yes
USE_REINPLACE=	yes

STRIP=		# none

.if defined(USE_AUTOMAKE) || defined(USE_AUTOMAKE_VER)
pre-everything::
	@${ECHO} ===========================================================
	@${ECHO} "You have 'USE_AUTOMAKE' or 'USE_AUTOMAKE_VER' variables"
	@${ECHO} "defined either in environment or in make(1) arguments."
	@${ECHO} "Please undefine them and try again."
	@${ECHO} ===========================================================
	@${FALSE}
.endif # defined(USE_AUTOMAKE) || defined(USE_AUTOMAKE_VER)

post-patch:
	@${MV} ${WRKSRC}/automake.texi ${WRKSRC}/automake${BUILD_VERSION}.texi
	@${RM} ${WRKSRC}/*.info* ${WRKSRC}/*.dvi >/dev/null 2>&1 || true

pre-configure:
	@${REINPLACE_CMD} -i -e "s,%%X11BASE%%,${X11BASE}," \
		${WRKSRC}/aclocal.in

pre-install:
	${RM} -fr ${PREFIX}/share/automake${BUILD_VERSION}
	${MKDIR} ${PREFIX}/share/automake${BUILD_VERSION}
	${MKDIR} ${PREFIX}/share/aclocal${BUILD_VERSION}
	${MKDIR} ${PREFIX}/libexec/automake${BUILD_VERSION}

post-install:
.for i in aclocal automake
	${LN} -sf ${PREFIX}/bin/${i}${BUILD_VERSION} \
		${PREFIX}/libexec/automake${BUILD_VERSION}/${i}
.endfor
	@install-info ${PREFIX}/info/automake${BUILD_VERSION}.info \
		${PREFIX}/info/dir

.include <bsd.port.mk>
