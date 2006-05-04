# New ports collection makefile for:	gbib
# Date created:			26 February 2002
# Whom:				Christian Brueffer (chris@unixpages.org)
#
# $FreeBSD$
#

PORTNAME=	gbib
PORTVERSION=	0.1.2
PORTREVISION=	5
CATEGORIES=	databases editors gnome
MASTER_SITES=	ftp://ftp.seul.org/pub/gbib/src/ \
		http://www.unixpages.org/distfiles/

PATCH_SITES=	${MASTER_SITE_DEBIAN}
PATCH_SITE_SUBDIR=	pool/main/g/gbib
PATCHFILES=	${PORTNAME}_${PORTVERSION}-3.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Editor/browser for BibTeX bibliographic databases

USE_X_PREFIX=	yes
USE_GNOME=	gnomelibs
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:213
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

CFLAGS+=	-fpermissive

post-patch:
	@${REINPLACE_CMD} -e 's|map.h,|map,|g ; \
		 s|vector.h,|vector,|g' ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e \
		's|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/aclocal.m4
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|CXXFLAGS = -g|CXXFLAGS = @CXXFLAGS@|g ; \
		 s|^exec_prefix =.*$$|exec_prefix = @exec_prefix@|g ; \
		 s|^datadir =.*$$|datadir = @datadir@|g ; \
		 s|^localedir =.*$$|localedir = $$(prefix)/share/locale|g ; \
		 s|^gnulocaledir =.*$$|gnulocaledir = $$(prefix)/share/locale|g'

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
