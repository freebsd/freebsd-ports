# New ports collection makefile for:	libgii
# Date created:		4 January 2000
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	libgii
PORTVERSION=	0.8.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/packages/ggi/ggi/v2.0/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggi
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GGI API for input sources

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

.if exists(/usr/include/kii/kii.h)
CONFIGURE_ARGS+=	--enable-kii
PLIST_SUB+=	KII=""
.else
PLIST_SUB+=	KII="@comment "
.endif

MAN1=		mhub.1
MAN3=		giiEventPoll.3 giiEventSend.3 giiInit.3 \
		giiOpen.3 giiPanic.3 giiSetEventMask.3 \
		giiMTInit.3 giiQueryDeviceInfo.3 \
		giiQueryDeviceInfoByNumber.3 giiQueryValInfo.3 \
		giiSplitInputs.3 gii_any_event.3 gii_cmd_event.3 \
		gii_cmd_nodata_event.3 gii_cmddata_getdevinfo.3 \
		gii_cmddata_getvalinfo.3 gii_event.3 gii_event_mask.3 \
		gii_event_type.3 gii_expose_event.3 gii_key_event.3 \
		gii_pbutton_event.3 gii_phystype.3 gii_pmove_event.3 \
		gii_val_event.3 gii_valrange.3
MAN7=		libgii.7 \
		filter-key.7 filter-keytrans.7 filter-mouse.7 \
		filter-save.7 filter-tcp.7 input-directx.7 \
		input-file.7 input-linux-evdev.7 input-linux-kbd.7 \
		input-linux-mouse.7 input-lk201.7 input-mouse.7 \
		input-tcp.7
MLINKS=		giiEventPoll.3 giiEventRead.3 \
		- giiEventSelect.3 - giiEventsQueued.3 \
		giiInit.3 giiExit.3 \
		giiOpen.3 giiClose.3 - giiJoinInputs.3 \
		giiSetEventMask.3 giiAddEventMask.3 \
		- giiGetEventMask.3 - giiRemoveEventMask.3
DOCSDIR=	share/doc/libgii
DOCS=		ChangeLog NEWS README \
		doc/env.txt doc/inputs.txt
EXAMPLESDIR=	share/examples/libgii
EXAMPLES=	demos/demo.c demos/filter.c \
		demos/mhub.c demos/xsendbut.c

post-configure:
	@${REINPLACE_CMD} -e 's/\(deplibs\) -lc/\1/;' ${WRKSRC}/libtool

post-install:
	@${CP} ${WRKSRC}/libgii.conf ${PREFIX}/etc/ggi/libgii.conf.dist
	@${CP} ${WRKSRC}/filter/mouse/mouse ${PREFIX}/etc/ggi/filter/mouse.dist
	@${CP} ${WRKSRC}/filter/keytrans/keytrans ${PREFIX}/etc/ggi/filter/keytrans.dist
	@${MAKE} install-examples
.if !defined(NOPORTDOCS)
	@${MAKE} install-documents
.endif

#################################################
# local targets for this port

install-examples:
	@${MKDIR} ${PREFIX}/${EXAMPLESDIR}
	@(cd ${WRKSRC} && \
	for i in ${EXAMPLES} ; do \
		${INSTALL_DATA} $${i} ${PREFIX}/${EXAMPLESDIR} ; \
	done)

install-documents:
	@${MKDIR} ${PREFIX}/${DOCSDIR}
	@(cd ${WRKSRC} && \
	for i in ${DOCS} ; do \
		${INSTALL_DATA} $${i} ${PREFIX}/${DOCSDIR} ; \
	done)

.include <bsd.port.mk>
