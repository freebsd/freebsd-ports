PREFIX?=	/usr/local
MANDIR=		${PREFIX}/man/ja/man
MROFF_CMD=	/usr/local/bin/groff -Tnippon -man

NOMLINKS=	yes

afterinstall:
.if defined(MLINKS) && !empty(MLINKS)
	@set `echo ${MLINKS} " " | sed 's/\.\([^.]\)\([^.]*\) /.\1\2 \1 /g'`; \
	while : ; do \
		case $$# in \
			0) break;; \
			[123]) echo "warn: empty MLINK: $$1 $$2 $$3"; break;; \
		esac; \
		name=$$1; shift; sect=$$1; shift; \
		l=${DESTDIR}${MANDIR}$${sect}${MANSUBDIR}/$$name; \
		name=$$1; shift; sect=$$1; shift; \
		t=${DESTDIR}${MANDIR}$${sect}${MANSUBDIR}/$$name; \
		${ECHO} $${t}${ZEXT} -\> $${l}${ZEXT}; \
		rm -f $${t} $${t}${MCOMPRESS_EXT}; \
		ln $${l}${ZEXT} $${t}${ZEXT}; \
	done
.endif
