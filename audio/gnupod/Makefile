# Created by: David Le Brun <david@dyn-ns.net>
# $FreeBSD$

PORTNAME=	gnupod
PORTVERSION=	0.99.8
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	SAVANNAH \
		http://www.blinkenlights.ch/gnupod-dist/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of Perl scripts for using an Apple iPod

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-MP3-Info>=0:audio/p5-MP3-Info \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-Unicode-String>=0:converters/p5-Unicode-String \
		p5-libwww>=0:www/p5-libwww \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1
RUN_DEPENDS:=	${BUILD_DEPENDS}

INFO=		gnupod

USES=		makeinfo perl5 tar:tgz
GNU_CONFIGURE=	yes
NO_BUILD=	yes
NO_ARCH=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	ac_cv_path_PERL=${PERL}

OPTIONS_DEFINE=	FLAC VORBIS DOCS

FLAC_BUILD_DEPENDS=	p5-Audio-FLAC-Header>=0:audio/p5-Audio-FLAC-Header
FLAC_RUN_DEPENDS=	p5-Audio-FLAC-Header>=0:audio/p5-Audio-FLAC-Header
VORBIS_BUILD_DEPENDS=	p5-Ogg-Vorbis-Header-PurePerl>=0:audio/p5-Ogg-Vorbis-Header-PurePerl \
			oggdec:audio/vorbis-tools
VORBIS_RUN_DEPENDS=	p5-Ogg-Vorbis-Header-PurePerl>=0:audio/p5-Ogg-Vorbis-Header-PurePerl \
			oggdec:audio/vorbis-tools

post-install:
	# It tries to guess where it should install it's Perl modules, gets it
	# wrong, and put them in BSDPAN, so move stuff at the right place.
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${MV} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/GNUpod ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	@${RMDIR} -p ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL} 2>/dev/null || :

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
.for file in gnupodrc.example gnutunesdb.example gnupod.html mkspl.html \
gnupod.texi fdl.texi version.texi ipod.svg
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
