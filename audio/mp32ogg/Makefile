# Created by: ijliao
# $FreeBSD$

PORTNAME=	mp32ogg
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	ftp://ftp.faceprint.com/pub/software/scripts/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	uqs
EXTRACT_SUFX=	# empty

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Convert MP3 files to Ogg Vorbis files

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info \
		p5-String-ShellQuote>=0:${PORTSDIR}/textproc/p5-String-ShellQuote

USE_PERL5=	yes
USES=		shebangfix
SHEBANG_FILES=	mp32ogg
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}/${PORTNAME}
NO_BUILD=	yes
PLIST_FILES=	bin/mp32ogg

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/mp32ogg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp32ogg ${PREFIX}/bin

.include <bsd.port.mk>
