# New ports collection makefile for:	autoconf
# Date created:		7 October 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	autoconf254
PORTVERSION=	2.54
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	autoconf

MAINTAINER=	AlanE@FreeBSD.org

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		help2man:${PORTSDIR}/misc/help2man
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

.undef		NO_IGNORE
BORKED=		"THIS IS A WORK IN PROGRESS. DON'T EVEN THINK ABOUT IT."
BROKEN=		${BORKED}
FORBIDDEN=	${BORKED}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CONFIG_SHELL=/bin/sh
CONFIGURE_ENV+=	M4=${LOCALBASE}/bin/gm4

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

MAN1=		autoconf.1	\
		autoheader.1	\
		autom4te.1	\
		autoreconf.1	\
		autoscan.1	\
		autoupdate.1	\
		config.guess.1	\
		config.sub.1	\
		ifnames.1

.if defined(USE_AUTOCONF) || defined(USE_AUTOCONF_VER)
pre-everything:
	@${ECHO} ===========================================================
	@${ECHO} "You have 'USE_AUTOCONF' or 'USE_AUTOCONF_VER' variables"
	@${ECHO} "defined either in environment or in make(1) arguments."
	@${ECHO} "Please undefine them and try again."
	@${ECHO} ===========================================================
	@${FALSE}
.endif # defined(USE_AUTOCONF) || defined(USE_AUTOCONF_VER)

post-install:
.for FILE in ${GENERIC_TOOLS}
	${INSTALL_SCRIPT} ${WRKSRC}/config/${FILE} ${PREFIX}/share/autoconf
.endfor

.include <bsd.port.mk>
