# New ports collection makefile for:	autoconf
# Date created:		7 October 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	autoconf257
PORTVERSION=	2.57
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	autoconf
DISTNAME=	autoconf-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org
COMMENT=	Automatically configure source code on many Un*x platforms

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		help2man:${PORTSDIR}/misc/help2man
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CONFIG_SHELL=${SH}
CONFIGURE_ENV+=	M4=${LOCALBASE}/bin/gm4
CONFIGURE_ARGS=	--program-suffix=257

.if ${PORTNAME} == "autoconf"
.if exists(${LOCALBASE}/bin/emacs)
PLIST_SUB+=	EMACS="" EMACSDIR=share/emacs
.elif exists(${LOCALBASE}/bin/xemacs)
PLIST_SUB+=	EMACS="" EMACSDIR=lib/xemacs
.else
PLIST_SUB+=	EMACS="@comment " EMACSDIR=""
.endif # no emacs found
.endif # ${PORTNAME} == "autoconf"

GENERIC_TOOLS=	config.guess	\
		config.sub	\
		elisp-comp	\
		install-sh	\
		mdate-sh	\
		missing		\
		mkinstalldirs

.if defined(USE_AUTOCONF) || defined(USE_AUTOCONF_VER)
pre-everything::
	@${ECHO} ===========================================================
	@${ECHO} "You have 'USE_AUTOCONF' or 'USE_AUTOCONF_VER' variables"
	@${ECHO} "defined either in environment or in make(1) arguments."
	@${ECHO} "Please undefine them and try again."
	@${ECHO} ===========================================================
	@${FALSE}
.endif # defined(USE_AUTOCONF) || defined(USE_AUTOCONF_VER)

post-install:
	${MKDIR} ${PREFIX}/share/autoconf257
.for FILE in ${GENERIC_TOOLS}
	${INSTALL_SCRIPT} ${WRKSRC}/config/${FILE} ${PREFIX}/share/autoconf257
.endfor

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages.mk"
.include <bsd.port.post.mk>
