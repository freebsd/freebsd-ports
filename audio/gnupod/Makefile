# Created by: David Le Brun <david@dyn-ns.net>
# $FreeBSD$

PORTNAME=	gnupod
PORTVERSION=	0.99.8
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		http://www.blinkenlights.ch/gnupod-dist/stable/
MASTER_SITE_SUBDIR=	gnupod
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of Perl scripts for using an Apple iPod

BUILD_DEPENDS=	p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-Unicode-String>=0:${PORTSDIR}/converters/p5-Unicode-String \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS:=	${BUILD_DEPENDS}

INFO=		gnupod
MAN1=		gnupod_addsong.pl.1 gnupod_check.pl.1 gnupod_INIT.pl.1 \
		gnupod_otgsync.pl.1 gnupod_search.pl.1 mktunes.pl.1 \
		tunes2pod.pl.1
MANCOMPRESSED=	yes

USES=		perl5
GNU_CONFIGURE=	yes
NO_BUILD=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	ac_cv_path_PERL=${PERL}

OPTIONS_DEFINE=	FLAC VORBIS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFLAC} || exists(${SITE_PERL}/${PERL_ARCH}/Audio/FLAC/Header.pm)
BUILD_DEPENDS+=	p5-Audio-FLAC-Header>=0:${PORTSDIR}/audio/p5-Audio-FLAC-Header
.endif

.if ${PORT_OPTIONS:MVORBIS} || exists(${SITE_PERL}/Ogg/Vorbis/Header/PurePerl.pm)
BUILD_DEPENDS+=	p5-Ogg-Vorbis-Header-PurePerl>=0:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header-PurePerl
BUILD_DEPENDS+=	oggdec:${PORTSDIR}/audio/vorbis-tools
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnupodrc.example ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnutunesdb.example ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnupod.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/mkspl.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnupod.texi ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/fdl.texi ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/version.texi ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/ipod.svg ${DOCSDIR}
.endif

.include <bsd.port.mk>
