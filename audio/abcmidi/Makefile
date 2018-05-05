# Created by: Sue Blake <sue@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abcmidi
DISTVERSION=	2015-09-28
CATEGORIES=	audio
MASTER_SITES=	http://ifdo.pugmarks.com/~seymour/runabc/
DISTNAME=	abcMIDI-${DISTVERSION:S/-/./g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert abc music files to MIDI and PostScript

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		zip
GNU_CONFIGURE=	yes

PORTDOCS=	*
PLIST_FILES=	${EXECUTABLES:S,^,bin/,} \
		${EXECUTABLES:S,^,man/man1/,:S,$,.1.gz,}

OPTIONS_DEFINE=	DOCS

EXECUTABLES=	abc2abc abc2midi abcmatch mftext midi2abc midicopy yaps

post-patch:
	@${REINPLACE_CMD} -e \
		's| -O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^docdir/s|= .*|= $${datadir}/doc/abcmidi| ; \
		 s|$${prefix}/||g ; \
		 s|$$(INSTALL) -m 755|$$(INSTALL_PROGRAM)| ; \
		 s|$$(INSTALL) -m 644|$$(INSTALL_DATA)|' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/programming
	(cd ${WRKSRC}/doc/programming && ${INSTALL_DATA} *.abc *.txt \
		${STAGEDIR}${DOCSDIR}/programming)

.include <bsd.port.mk>
