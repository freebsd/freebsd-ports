# New ports collection makefile for:	libgiigic
# Date created:				7 December 2004
# Whom:					antoine.brodin@laposte.net
#
# $FreeBSD$
#

PORTNAME=	libgiigic
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.ggi-project.org/ftp/ggi/v2.2/ \
		SF/ggi/ggi-libs/${PORTNAME}-${PORTVERSION}		

DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	antoine.brodin@laposte.net
COMMENT=	A library on top of libgii, gic stands for General Input Configuration

LIB_DEPENDS=	gii.1:${PORTSDIR}/devel/libgii

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"

MAN3=		gicActionLazyAction.3 \
		gicActionWrite.3 \
		gicContextAllocate.3 \
		gicControlAllocate.3 \
		gicFeatureActivate.3 \
		gicFeatureAllocate.3 \
		gicFeatureAttachAction.3 \
		gicFeatureAttachRecognizerDriver.3 \
		gicFeatureMapActions.3 \
		gicFeatureWrite.3 \
		gicHeadAllocate.3 \
		gicInit.3 \
		gicInputRegister.3 \
		gicOpen.3 \
		gicRecognizerDriverRegister.3 \
		gicRecognizerTrain.3 \
		gicRecognizerWrite.3 \
		gic_context.3 \
		gic_control.3 \
		gic_feature.3 \
		gic_head.3
MAN7=		libgiigic-usage.7 \
		libgiigic.7
MLINKS=		gicActionLazyAction.3 gicActionLazyGetstate.3 \
		- gicActionLazyReset.3 \
		gicActionWrite.3 gicActionMapActions.3 \
		gicContextAllocate.3 gicContextAttachControl.3 \
		- gicContextDetachControl.3 - gicContextFindConflict.3 \
		- gicContextFree.3 - gicContextGetControl.3 \
		- gicContextGetName.3 - gicContextHandleEvent.3 \
		- gicContextLookupControl.3 - gicContextMapActions.3 \
		- gicContextNumControls.3 - gicContextRead.3 \
		- gicContextWrite.3 \
		gicControlAllocate.3 gicControlAttachFeature.3 \
		- gicControlDetachFeature.3 - gicControlFindConflict.3 \
		- gicControlFree.3 - gicControlGetFeature.3 \
		- gicControlGetName.3 - gicControlHandleEvent.3 \
		- gicControlLookupFeature.3 - gicControlMapActions.3 \
		- gicControlNumFeatures.3 - gicControlRead.3 \
		- gicControlWrite.3 \
		gicInit.3 gicExit.3 \
		gicFeatureActivate.3 gicFeatureHandleEvent.3 \
		gicFeatureAttachAction.3 gicFeatureDetachAction.3 \
		gicFeatureAttachRecognizerDriver.3 \
		gicFeatureAttachRecognizer.3 - gicFeatureDetachRecognizer.3 \
		- gicFeatureGetName.3 - gicFeatureGetRecognizer.3 \
		- gicFeatureNumRecognizers.3 \
		gicFeatureAllocate.3 gicFeatureFree.3 \
		gicFeatureMapActions.3 gicFeatureFindConflict.3 \
		gicFeatureWrite.3 gicFeatureRead.3 \
		gicHeadAllocate.3 gicHeadAttachContext.3 \
		- gicHeadDetachContext.3 - gicHeadFree.3 \
		- gicHeadGetContext.3 - gicHeadLookupContext.3 \
		- gicHeadMapActions.3 - gicHeadNumContexts.3 \
		- gicHeadRead.3 - gicHeadWrite.3 \
		gicOpen.3 gicClose.3 \
		gicRecognizerDriverRegister.3 gicRecognizerDriverLookup.3 \
		- gicRecognizerDriverUnregister.3 \
		gicRecognizerTrain.3 gicRecognizerFindConflict.3 \
		- gicRecognizerGetName.3 - gicRecognizerGetOpposite.3 \
		- gicRecognizerTrainAdd.3 - gicRecognizerTrainMove.3 \
		- gicRecognizerTrainStart.3 - gicRecognizerTrainStop.3

post-install:
	${INSTALL_DATA} ${WRKSRC}/libgiigic.conf ${PREFIX}/etc/ggi/libgiigic.conf.dist

.include <bsd.port.mk>
