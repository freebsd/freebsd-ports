# New ports collection makefile for:	Pd
# Date created:				2002-05-24
# Whom:					Trevor Johnson <trevor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pd
DISTVERSION=	0.43-0
DISTVERSIONSUFFIX=	.src
CATEGORIES=	audio
MASTER_SITES=	http://www-crca.ucsd.edu/~msp/Software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIDI-capable real-time audio processor/synthesizer

LICENSE=	BSD

WRKSRC=		${WRKDIR}/${DISTNAME:S;.src;/src;}
PATCH_WRKSRC=	${WRKSRC}/..

USE_TCL_BUILD=	yes
USE_TK_BUILD=	yes
USE_TK_WRAPPER=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
MAKEFILE=	makefile
MAKE_JOBS_UNSAFE=	yes

MAN1=		pd.1 pdreceive.1 pdsend.1

CPPFLAGS=	-I${TCL_INCLUDEDIR}
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${PATCH_WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|__FreeBSD_kernel__|__FreeBSD__|g ; \
		 s|<alloca\.h>|<stdlib.h>|g'
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|CPPFLAGS="-D|CPPFLAGS="$$CPPFLAGS -D|g ; \
		 s|LDFLAGS="-Wl,|LDFLAGS="$$LDFLAGS -Wl,|g ; \
		 s|-ltcl8[0-9]|-ltcl${USE_TCL}|g ; \
		 s|-ltk8[0-9]|-ltk${USE_TK}|g ; \
		 s|s_midi_oss.c ||g ; \
		 /uname/s|Linux|${OPSYS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|$$(WARN_CFLAGS)||g ; \
		 s|$$(MORECFLAGS)||g ; \
		 s|x_midi.c ||g ; \
		 s|s_midi.c ||g ; \
		 s|INCLUDE) -o|INCLUDE) $$(LDFLAGS) -o|g' ${WRKSRC}/makefile.in
	@${REINPLACE_CMD} -e \
		's|PD_BASEDIR/LICENSE|${DOCSDIR}/LICENSE|g ; \
		 s|PD_BASEDIR/doc/1|${DOCSDIR}/1|g' \
			${WRKSRC}/../doc/1.manual/1.introduction.txt

do-install:
.for file in pd pdreceive pdsend
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/${file} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/m_pd.h ${PREFIX}/include
.for file in pd pdreceive pdsend
	${INSTALL_MAN} ${WRKSRC}/../man/${file}.1 ${MANPREFIX}/man/man1
.endfor
	@${MKDIR} ${PREFIX}/lib/pd
	@(${TAR} -C ${WRKSRC}/../extra --exclude "*.bak" --exclude "*.orig" \
		-cf - . | ${TAR} -C ${PREFIX}/lib/pd --unlink -xf -)
	@${CHOWN} -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/pd
	@${FIND} ${PREFIX}/lib/pd -type d -exec ${CHMOD} 755 {} \;
	@${FIND} ${PREFIX}/lib/pd -type f -exec ${CHMOD} ${LIBMODE} {} \;
	@${MKDIR} ${PREFIX}/lib/pd/bin
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/pd-watchdog ${PREFIX}/lib/pd/bin
	@${MKDIR} ${PREFIX}/lib/pd/tcl
	${INSTALL_DATA} ${WRKSRC}/../tcl/*.tcl ${PREFIX}/lib/pd/tcl
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(${TAR} -C ${WRKSRC}/../doc --exclude "*.bak" --exclude "*.orig" \
		-cf - . | ${TAR} -C ${DOCSDIR} --unlink -xf -)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${FIND} ${DOCSDIR} -type d -exec ${CHMOD} 755 {} \;
	@${FIND} ${DOCSDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
.for file in LICENSE.txt README.txt
	${INSTALL_DATA} ${WRKSRC}/../${file} ${DOCSDIR}
.endfor
	@${LN} -sf ${DOCSDIR} ${PREFIX}/lib/pd/doc
.endif

.include <bsd.port.mk>
