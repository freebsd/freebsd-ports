# New ports collection makefile for:	autoconf
# Date created:		7 October 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	autoconf
PORTVERSION=	2.53
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	autoconf

MAINTAINER=	ade@FreeBSD.org
COMMENT=	Automatically configure source code on many Un*x platforms (version 2.53)

DEPRECATED=	Please use devel/autoconf259 instead
EXPIRATION_DATE=31st December 2004

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		help2man:${PORTSDIR}/misc/help2man
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

BUILD_VERSION=	253
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
LATEST_LINK=	autoconf${BUILD_VERSION}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_RUN=	yes
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIG_SHELL=${SH} M4=${LOCALBASE}/bin/gm4
CONFIGURE_ARGS=	--program-suffix=${BUILD_VERSION} --without-lispdir
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

GENERIC_TOOLS=	config.guess config.sub	elisp-comp install-sh mdate-sh \
		missing mkinstalldirs

MAN1_PAGES=	autoconf autoheader autom4te autoreconf autoscan \
		autoupdate config.guess config.sub ifnames
MAN1=		${MAN1_PAGES:S/$/${BUILD_VERSION}.1/g}

.if defined(USE_AUTOCONF) || defined(USE_AUTOCONF_VER)
pre-everything::
	@${ECHO} ===========================================================
	@${ECHO} "You have 'USE_AUTOCONF' or 'USE_AUTOCONF_VER' variables"
	@${ECHO} "defined either in environment or in make(1) arguments."
	@${ECHO} "Please undefine them and try again."
	@${ECHO} ===========================================================
	@${FALSE}
.endif # defined(USE_AUTOCONF) || defined(USE_AUTOCONF_VER)

post-patch:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} -E 's,(PACKAGE=autoconf),\1${BUILD_VERSION},' configure)
	@(cd ${WRKSRC}/man && \
		for file in *.[1x]; do \
			${REINPLACE_CMD} -E 's,([^-]auto)(conf|make|reconf|update|header|scan),\1\2${BUILD_VERSION},g ; \
						s,(config\.guess|config\.sub|ifnames),\1${BUILD_VERSION},g' $$file ; \
		done)
	@(cd ${WRKSRC}/doc && \
		${RM} -f *.info && \
		${MV} autoconf.texi autoconf${BUILD_VERSION}.texi && \
		${MV} standards.texi standards${BUILD_VERSION}.texi && \
		${REINPLACE_CMD} -E 's,(autoconf)\),\1${BUILD_VERSION}\),g' autoconf${BUILD_VERSION}.texi && \
		${REINPLACE_CMD} -E 's,(autoconf|standards)\.(info|texi),\1${BUILD_VERSION}\.\2,g' Makefile.in)

post-install:
.for FILE in ${GENERIC_TOOLS}
	${INSTALL_SCRIPT} ${WRKSRC}/config/${FILE} ${PREFIX}/share/autoconf${BUILD_VERSION}
.endfor
	@-${RM} -fr ${PREFIX}/libexec/autoconf${BUILD_VERSION}
	${MKDIR} ${PREFIX}/libexec/autoconf${BUILD_VERSION}
.for i in autoconf autoheader autoreconf autoscan autoupdate ifnames
	${LN} -sf ${PREFIX}/bin/${i}${BUILD_VERSION} \
		${PREFIX}/libexec/autoconf${BUILD_VERSION}/${i}
.endfor

.include <bsd.port.mk>
