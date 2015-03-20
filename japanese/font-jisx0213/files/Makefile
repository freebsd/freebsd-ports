# $FreeBSD$
.SUFFIXES:
.SUFFIXES: .bdf .pcf

.if defined(STAGEDIR) && !empty(STAGEDIR)
PREFIX:=	${STAGEDIR}${PREFIX}
.endif
LOCALBASE?=	/usr/local
GZIP_CMD?=	/usr/bin/gzip
MKBOLD_CMD?=	${LOCALBASE}/bin/mkbold
MKITALIC_CMD?=	${LOCALBASE}/bin/mkitalic
BDFTOPCF_CMD?=	${LOCALBASE}/bin/bdftopcf

SRCS=	K12-1.bdf K12-2.bdf \
	K14-2004-1.bdf K14-2000-1.bdf K14-2000-2.bdf \
	jiskan16-2004-1.bdf jiskan16-2000-1.bdf jiskan16-2000-2.bdf \
	jiskan24-2000-1.bdf jiskan24-2000-2.bdf

TARGETS=${SRCS:S/.bdf/.pcf.gz/} \
	${SRCS:S/.bdf/b.pcf.gz/} \
	${SRCS:S/.bdf/i.pcf.gz/} \
	${SRCS:S/.bdf/bi.pcf.gz/} 

all: ${TARGETS}

.bdf.pcf:
	${BDFTOPCF_CMD} $> > $@
CLEANFILES+=	${SRCS:S/.bdf/.pcf/}
.for B in ${SRCS:S/.bdf//}
${B}.pcf.gz: ${B}.pcf
	${GZIP_CMD} -c $> > $@
CLEANFILES+=	${B}.pcf.gz
.endfor

# bold
.for B in ${SRCS:S/.bdf//}
${B}b.bdf: ${B}.bdf
	${MKBOLD_CMD} $> > $@
${B}b.pcf: ${B}b.bdf
	${BDFTOPCF_CMD} $> > $@
${B}b.pcf.gz: ${B}b.pcf
	${GZIP_CMD} -c $> > $@
CLEANFILES+=	${B}b.bdf ${B}b.pcf ${B}b.pcf.gz
.endfor

# italic
.for B in ${SRCS:S/.bdf//}
${B}i.bdf: ${B}.bdf
	${MKITALIC_CMD} $> > $@
${B}i.pcf: ${B}i.bdf
	${BDFTOPCF_CMD} $> > $@
${B}i.pcf.gz: ${B}i.pcf
	${GZIP_CMD} -c $> > $@

${B}bi.bdf: ${B}b.bdf
	${MKITALIC_CMD} $> > $@
${B}bi.pcf: ${B}bi.bdf
	${BDFTOPCF_CMD} $> > $@
${B}bi.pcf.gz: ${B}bi.pcf
	${GZIP_CMD} -c $> > $@
CLEANFILES+=	${B}i.bdf ${B}bi.bdf \
		${B}i.pcf ${B}bi.pcf \
		${B}i.pcf.gz ${B}bi.pcf.gz
.endfor

install::
	mkdir -p ${PREFIX}/${FONTDIR}
	${BSD_INSTALL_DATA} ${TARGETS} ${PREFIX}/${FONTDIR}

clean::
	rm -f ${TARGETS} ${CLEANFILES}
