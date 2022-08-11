PORTNAME=	ample
PORTVERSION=	0.5.7
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows you to listen to your own MP3's away from home

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir="${PREFIX}/var"

PLIST_FILES=	bin/ample man/man1/ample.1.gz man/man5/ample.conf.5.gz \
		man/man5/ample.html.5.gz
PLIST_DIRS=	var/log

post-configure:
	@${REINPLACE_CMD} -E '/INSTALL/ s,\((bin|log)dir\),\(DESTDIR\)$$&,g' \
		${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -E '/INSTALL/ s,\(MAN(1|5)PATH\),\(DESTDIR\)$$&,g' \
		${WRKSRC}/docs/Makefile

.include <bsd.port.mk>
