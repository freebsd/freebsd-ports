# Created by: Dishanker Rajakulendren <draj@oceanfree.net>
# $FreeBSD$

PORTNAME=	RealTimeBattle
PORTVERSION=	1.0.8
DISTVERSIONSUFFIX=	-Ext
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}-1.0.x/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot programming game for UNIX

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed

USES=		compiler:c++11-lang dos2unix gettext gmake gnome \
		localbase:ldflags perl5 pkgconfig python:2.7 tar:bzip2
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rtb-dir=${PREFIX}/lib/${PORTNAME}
DOS2UNIX_FILES=	team-framework/bots/cobra/cobra_clientspecificrepository.h

INFO=		RealTimeBattle
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

DESKTOP_ENTRIES="${PORTNAME}" "" "" "${PORTNAME:tl}" "" ""

OPTIONS_DEFINE=	DOCS

post-patch:
.for i in configure
	@${REINPLACE_CMD} -e 's|INCLUDED_LIBINTL=yes|INCLUDED_LIBINTL=no|g ; \
		 s|\\$${top_builddir}/intl/libintl.a|-lintl|g ; \
		 /^DOCS_DIR/s|=.*|=$${prefix}/share/doc/${PORTNAME}| ; \
		 /test/s| == | = |g' ${WRKSRC}/${i}
.endfor
.for i in Documentation/Makefile.in
	@${REINPLACE_CMD} -e '/COPYING/d' ${WRKSRC}/${i}
.endfor
.for i in team-framework/createrobot.sh \
	team-framework/createrobotconf.sh
	@${REINPLACE_CMD} -e 's| sed| gsed|g' ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
