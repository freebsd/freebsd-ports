# Created by: Hiroki Sato <hrs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdsreader
PORTVERSION=	0.3.2
CATEGORIES=	cad
MASTER_SITES=	http://home.netcom.com/~serbanp/
DISTNAME=	GDSreader.${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GDS2 stream file to Postscript and HP/GL converter

MAN1=		gdsreader.1 maptolayer.1
PORTDOCS=	README README.povray ChangeLog
EXFILES=	layers.config test.gds layers.config.7HP.5ML \
		layers.config.5AM.4ML
PLIST_FILES=	bin/gdsreader bin/maptolayer \
		${EXFILES:S,^,${EXAMPLESDIR_REL}/,}
PLIST_DIRS=	${EXAMPLESDIR_REL}

NO_STAGE=	yes

.include <bsd.port.options.mk>

post-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} install-data
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} install-docs
.endif

.include <bsd.port.mk>
