USE_IMAKE=	yes
DISTNAME=	pixmap
LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
MASTER_SITES=	ftp://ftp.x.org/pub/R6untarred/contrib/programs/

.if !defined(MASTER_SITE_OVERRIDE)

fetch:	pre-fetch
	@if [ ! -d ${DISTDIR} ]; then mkdir -p ${DISTDIR}; fi
	@(cd ${DISTDIR}; \
	 for file in ${DISTFILES}; do \
		if [ ! -f $$file -a ! -f `basename $$file` ]; then \
			echo ">> $$file doesn't seem to exist on this system."; \
			echo ">> Attempting to fetch it from a master site."; \
			for site in ${MASTER_SITES}; do \
				if ${NCFTP} -c ${NCFTPFLAGS} $${site}$${file} >$$file; then \
					break; \
				fi \
			done; \
			if [ ! -f $$file -a ! -f `basename $$file` ]; then \
				echo ">> Couldn't fetch it - please try to retreive this";\
				echo ">> port manually into ${DISTDIR} and try again."; \
				exit 1; \
			fi; \
	    fi \
	 done)
.endif

pre-patch:
	@(cd ${WRKDIR}; mv pub/R6untarred/contrib/programs/pixmap .)
.include <bsd.port.mk>
