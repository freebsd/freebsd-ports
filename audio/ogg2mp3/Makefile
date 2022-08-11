PORTNAME=	ogg2mp3
PORTVERSION=	0.6.1
PORTREVISION?=	3
CATEGORIES=	audio

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Perl script that converts Ogg Vorbis files to MP3 format

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

RUN_DEPENDS=	lame:audio/lame \
		p5-String-ShellQuote>=0:textproc/p5-String-ShellQuote \
		ogginfo:audio/vorbis-tools

USES=		perl5 shebangfix tar:tgz
USE_GITHUB=	yes
GH_ACCOUNT=	fithp
GH_TAGNAME=	f3bee47c3bce01a33b5bce88fa70bd9ecadca0ad

SHEBANG_FILES=	ogg2mp3

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/ogg2mp3

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" ${WRKSRC}/ogg2mp3

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ogg2mp3 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
