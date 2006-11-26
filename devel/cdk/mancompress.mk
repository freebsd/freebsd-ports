#
# $FreeBSD$
#
# this files is a workaround for the target in bsd.port.mk
# which breaks when the list of MLINKS gets > 32k
#

# Compress (or uncompress) and symlink manpages.
compress-man::
	@${ECHO_MSG} "===>   Compressing manual pages for ${PKGNAME}"
	@_manpages='${_MANPAGES:S/'/'\''/g}' && [ "$${_manpages}" != "" ] && ( eval ${GZIP_CMD} $${_manpages} ) || ${TRUE}
	${ECHO_CMD} '${MLINKS}' | \
	${AWK} -v MAN="${MANPREFIX}/man/man3/" \
	'{ for (i=1; i<=NF; i+=2) \
		{ print MAN $$i ".gz " MAN $$(i+1) ".gz" } }' | \
	while read regular link; do \
		${ECHO_CMD} $${regular} $${link}; \
		${RM} -f $${link%.gz}; ${RM} -f $${link%.gz}.gz; \
		${LN} -fs `${ECHO_CMD} $${regular} $${link} | ${AWK} '{ \
			z=split($$1, a, /\//); x=split($$2, b, /\//); \
			while (a[i] == b[i]) i++; \
			for (q=i; q<x; q++) printf "../"; \
			for (; i<z; i++) printf a[i] "/"; printf a[z]; }'` $${link}; \
	done

