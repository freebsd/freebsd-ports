# New ports collection makefile for:	automake17
# Date created:		15 Feb 2003
# Whom:			Udo Schweigert
#
# $FreeBSD$
#

PORTNAME=	automake17
PORTVERSION=	1.7.2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	automake
DISTNAME=	automake-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU automake generates input files for GNU autoconf

BROKEN=		Needs at least autoconf 254 to build.

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PERL5}
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

pre-configure:
	@${REINPLACE_CMD} -i -e "s,%%X11BASE%%,${X11BASE}," \
		${WRKSRC}/aclocal.in

pre-install:
	${RM} -fr ${PREFIX}/libexec/automake17
	${MKDIR} ${PREFIX}/libexec/automake17

post-install:
.for i in aclocal automake
	${LN} -sf ${PREFIX}/bin/${i}17 \
		${PREFIX}/libexec/automake17/${i}
.endfor
	@install-info ${PREFIX}/info/automake17.info \
		${PREFIX}/info/dir

.include <bsd.port.mk>
