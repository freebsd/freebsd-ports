# New ports collection makefile for:	ecasound
# Date created:		22 dec 2000
# Whom:			The Anarcat <anarcat@anarcat.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	ecasound
PORTVERSION=	2.0.3
CATEGORIES=	audio
MASTER_SITES=	http://ecasound.seul.org/download/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ecasound

MAINTAINER=	anarcat@anarcat.dyndns.org

USE_GMAKE=	yes
USE_AUTOMAKE_VER=14
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS+=	--enable-sys-readline
MAKE_ENV+=	${CONFIGURE_ENV}

.if defined(WITH_MPG123)
RUN_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
.endif

.if defined(WITH_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if defined(WITH_MIKMOD)
RUN_DEPENDS+=	mikmod:${PORTSDIR}/audio/mikmod
.endif

.if defined(WITH_AUDIOFILE)
# very crappy hack to detect audiofile properly
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
		CXXFLAGS="-I${LOCALBASE}/include ${CXXFLAGS}"
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile
.else
CONFIGURE_ARGS+=	--disable-audiofile
.endif

#.if defined(WITH_PYECASOUND)
#USE_PYTHON=	yes
#PLIST_SUB+=	WITH_PYECASOUND=""
#.else
CONFIGURE_ARGS+=	--disable-pyecasound
PLIST_SUB+=	WITH_PYECASOUND="@comment "
#.endif

.if !defined(WITH_OPTIMIZED_CFLAGS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-configure.in-optimizations
.endif

MAN1=		ecasound-iam.1 ecasound.1 ecatools.1
MAN5=		ecasoundrc.5

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif
.if !defined(WITH_AUDIOFILE)
	@${ECHO_MSG} "You can enable AUDIOFILE support by defining WITH_AUDIOFILE."
.endif

post-patch:
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${PERL} -pi -e 's!-O2 -ffast-math!!' ${WRKSRC}/kvutils/Makefile.am
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ecasound
	${MKDIR} ${PREFIX}/share/doc/ecasound/programmers_guide
	${MKDIR} ${PREFIX}/share/doc/ecasound/users_guide
	${INSTALL_MAN} ${WRKSRC}/Documentation/*.html ${WRKSRC}/Documentation/*.txt \
		${PREFIX}/share/doc/ecasound
	${INSTALL_MAN} ${WRKSRC}/Documentation/programmers_guide/*.html \
		${PREFIX}/share/doc/ecasound/programmers_guide
	${INSTALL_MAN} ${WRKSRC}/Documentation/users_guide/*.html \
		${PREFIX}/share/doc/ecasound/users_guide
.endif

#	strip ${PREFIX}/bin/ecaconvert ${PREFIX}/bin/ecafixdc \
#${PREFIX}/bin/ecanormalize ${PREFIX}/bin/ecaplay ${PREFIX}/bin/ecasignalview \
#${PREFIX}/bin/ecasound ${PREFIX}/bin/ecasound-config ${PREFIX}/bin/ecasoundc-config

.include <bsd.port.mk>
