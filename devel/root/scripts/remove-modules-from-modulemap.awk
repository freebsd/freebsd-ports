BEGIN {
  exclude = exclude; #trim left and right
  gsub(/[[:blank:]]/, "|", exclude);
  gsub(/\//, "\\/", exclude);
  ex_regx = "module[[:blank:]]+\"(" exclude ")\".*{[[:blank:]]*$";
}

$0 ~ ex_regx, $0 ~ /^[[:blank:]]*}[[:blank:]]*$/  { next ; }
{print}
