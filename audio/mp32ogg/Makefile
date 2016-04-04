# Created by: ijliao
# $FreeBSD$

PORTNAME=	mp32ogg
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	ftp://ftp.faceprint.com/pub/software/scripts/ \
		LOCAL/uqs
EXTRACT_SUFX=	# empty

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Convert MP3 files to Ogg Vorbis files

RUN_DEPENDS=	mpg123:audio/mpg123 \
		oggenc:audio/vorbis-tools \
		p5-MP3-Info>=0:audio/p5-MP3-Info \
		p5-String-ShellQuote>=0:textproc/p5-String-ShellQuote

USES=		shebangfix perl5
SHEBANG_FILES=	mp32ogg
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}/${PORTNAME}
PLIST_FILES=	bin/mp32ogg

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/mp32ogg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp32ogg ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
