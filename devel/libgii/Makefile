# New ports collection makefile for:	libgii
# Date created:		4 January 2000
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	libgii
PORTVERSION=	0.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/ggi/ggi/2_0_beta_2.1/

MAINTAINER=	mwest@uct.ac.za

USE_BZIP2=	yes
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
# NOTE: We can not define USE_LIBTOOL for this port to build.
#USE_LIBTOOL=	yes
CFLAGS+=	${PTHREAD_LIBS}

MAN1=		mhub.1
MAN3=		giiEventPoll.3gii giiInit.3gii giiOpen.3gii \
		giiPanic.3gii giiSetEventMask.3gii
MLINKS=		giiEventPoll.3gii giiEventRead.3gii - giiEventSend.3gii \
		giiInit.3gii giiExit.3gii \
		giiOpen.3gii giiClose.3gii - giiJoinInputs.3gii \
		giiSetEventMask.3gii giiAddEventMask.3gii \
		- giiGetEventMask.3gii - giiRemoveEventMask.3gii

DOCSDIR=	share/doc/libgii
DOCS=		ChangeLog NEWS README \
		doc/env.txt doc/inputs.txt doc/libgii-api.sgml
EXAMPLESDIR=	share/examples/libgii
EXAMPLES=	demos/demo.c demos/filter.c \
		demos/mhub.c demos/xsendbut.c

post-configure:
	@${PERL} -p -i.bak -e 's/deplibs -lc/deplibs/;' ${WRKSRC}/libtool

post-install:
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
