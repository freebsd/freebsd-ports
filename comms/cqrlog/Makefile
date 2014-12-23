# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cqrlog
PORTVERSION=	1.8.2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.cqrlog.com/files/cqrlog_${PORTVERSION}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	shurd
DISTNAME=	${PORTNAME}_${PORTVERSION}.src

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio logging application

LICENSE=	GPLv2

BUILD_DEPENDS=	lazbuild:${PORTSDIR}/editors/lazarus
LIB_DEPENDS=	libhamlib.so:${PORTSDIR}/comms/hamlib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_FPC=	gtk2
ALL_TARGET=	${PORTNAME}

GETLAZDIR=	${AWK} '/cd .* .* exit/ { print $$2 }' ${LOCALBASE}/bin/lazarus

pre-build:
	${REINPLACE_CMD} -e s!%%LAZSHAREDIR%%!`${GETLAZDIR}`!g \
		${WRKSRC}/environmentoptions.xml
	# We're basically copying the entire editors/lazarus
	# port into WRKSRC since lazbuild modifies all sorts
	# of files in the lazarus dir during builds.
	${CP} -R `${GETLAZDIR}` ${WRKSRC}/lazdir
	${CHMOD} -R u+w ${WRKSRC}/lazdir

post-patch:
	@${SED} -e s!%%LOCALBASE%%!${LOCALBASE}!g \
		-e s!%%MAKE_CMD%%!${MAKE_CMD}!g \
		-e s!%%WRKSRC%%!${WRKSRC}!g \
		${FILESDIR}/environmentoptions.xml.in \
		> ${WRKSRC}/environmentoptions.xml
	${REINPLACE_CMD} -e s!%%LOCALBASE%%!${LOCALBASE}!g \
		${WRKSRC}/src/dData.pas ${WRKSRC}/src/dUtils.pas \
		${WRKSRC}/src/fLoTWExport.pas ${WRKSRC}/src/fPreferences.pas \
		${WRKSRC}/src/fRotControl.pas ${WRKSRC}/src/fTRXControl.pas \
		${WRKSRC}/src/fGrayline.pas
	${REINPLACE_CMD} -e s!%%PREFIX%%!${PREFIX}!g \
		${WRKSRC}/src/dData.pas ${WRKSRC}/src/fGrayline.pas

.include <bsd.port.mk>
